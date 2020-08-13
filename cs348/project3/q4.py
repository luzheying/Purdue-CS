##########
# q4.py
# expects two command line arguments:
#  - HDFS dir containing account.asc, card.asc, client.asc, disp.asc, loan.asc, order.asc, and trans.asc
#    (no trailing forward-slash)
#  - HDFS dir to write results
##########

from pyspark import SparkConf, SparkContext
from pyspark.sql import *
from pyspark.sql.types import *
import sys

# create a spark context;
# these two lines not needed if running pyspark shell;
conf = SparkConf().setAppName("spark query")
sc = SparkContext(conf=conf)

# we will read tables from HDFS and register them with Spark SQL;
# to do this, we need a Spark SQL context;
sqlContext = SQLContext(sc)

# table order;
#lines = sc.textFile(sys.argv[1] + "/order.asc")
#parts = lines.map(lambda l: l.split(";"))
#parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3], p[4], p[5].strip()))
#schemaString = "order_id account_id bank_to account_to amount k_symbol"
#fields = [
#    StructField(field_name, StringType(), True) for field_name in schemaString.split()
#]
#schema = StructType(fields)
#schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
#schemaDF.registerTempTable("order")

# table disp;
lines = sc.textFile(sys.argv[1] + "/disp.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3].strip()))
schemaString = "disp_id client_id account_id type"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("disp")

# table trans;
lines = sc.textFile(sys.argv[1] + "/trans.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9].strip()))
schemaString = "trans_id account_id date type operation amount balance k_symbol bank account"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("trans")

# table loan;
lines = sc.textFile(sys.argv[1] + "/loan.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3], p[4], p[5], p[6].strip()))
schemaString = "loan_id account_id date amount duration payments status"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("loan")

# try these commands in pyspark shell:
# lines.count()
# lines.first()
# parts.first()
# users.first()
query = ("SELECT new.client_id, CASE WHEN new.loan_count > new.tran_count THEN new.loan_count ELSE new.tran_count END larger FROM"
+ "(SELECT d.client_id, count(l.amount) loan_count, count(t.amount) tran_count "
  + "FROM disp AS d left join loan AS l on d.account_id = l.account_id "
  + "left join trans AS t on d.account_id = t.account_id GROUP BY d.client_id ) new ")
results = sqlContext.sql(query)

# write data back to HDFS;
# repartition down to 10 partitions to reduce number of HDFS files written;
results.rdd.map(lambda p: str(p.client_id) + ";" + str(p.larger)).repartition(10).saveAsTextFile(sys.argv[2])


