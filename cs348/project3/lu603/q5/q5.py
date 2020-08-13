##########
# q5.py
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
lines = sc.textFile(sys.argv[1] + "/order.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3], p[4], p[5].strip()))
schemaString = "order_id account_id bank_to account_to amount k_symbol"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("order")

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

# table client;
lines = sc.textFile(sys.argv[1] + "/client.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2].strip()))
schemaString = "client_id birth_date district_id"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("client")

# table district;
lines = sc.textFile(sys.argv[1] + "/district.asc")
parts = lines.map(lambda l: l.split(";"))
parts_stripped = parts.map(lambda p: (p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14], p[15].strip()))
schemaString = "district_id A2 A3 A4 A5 A6 A7 A8 A9 A10 A11 A12 A13 A14 A15 A16"
fields = [
    StructField(field_name, StringType(), True) for field_name in schemaString.split()
]
schema = StructType(fields)
schemaDF = sqlContext.createDataFrame(parts_stripped, schema)
schemaDF.registerTempTable("district")


# try these commands in pyspark shell:
# lines.count()
# lines.first()
# parts.first()
# users.first()

query = ("SELECT tr.client_id, tr.tran_sum + lo.loan_sum + ord.order_sum as total FROM " +
        "(SELECT c.client_id, sum(ifnull(t.amount,0)) AS tran_sum FROM client AS c " +
"join disp AS d on c.client_id = d.client_id left join trans AS t on d.account_id = t.account_id " +
"WHERE c.client_id IN (SELECT c.client_id FROM client AS c, district AS dis WHERE c.district_id = dis.district_id AND dis.A2 <> 'Zlin' group by c.client_id) " +
"group by c.client_id) AS tr, " +
"(SELECT c.client_id, sum(ifnull(l.amount,0)) AS loan_sum FROM client AS c " +
"join disp AS d on c.client_id = d.client_id left join loan AS l on d.account_id = l.account_id " +
"WHERE c.client_id IN (SELECT c.client_id FROM client AS c, district AS dis WHERE c.district_id = dis.district_id AND dis.A2 <> 'Zlin' group by c.client_id) "+
"group by c.client_id) AS lo, " +
"(SELECT c.client_id, sum(ifnull(o.amount,0)) AS order_sum FROM client AS c " +
"join disp AS d on c.client_id = d.client_id left join order AS o on d.account_id = o.account_id " +
"WHERE c.client_id IN (SELECT c.client_id FROM client AS c, district AS dis WHERE c.district_id = dis.district_id AND dis.A2 <> 'Zlin' group by c.client_id) "+
"group by c.client_id) AS ord " +
"WHERE tr.client_id = lo.client_id " +
"AND lo.client_id = ord.client_id ")
results = sqlContext.sql(query)

# write data back to HDFS;
# repartition down to 10 partitions to reduce number of HDFS files written;
results.rdd.map(lambda p: str(p.client_id) + ";" + str(p.total)).repartition(10).saveAsTextFile(sys.argv[2])


