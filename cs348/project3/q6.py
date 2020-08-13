##########
# q6.py
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


# try these commands in pyspark shell:
# lines.count()
# lines.first()
# parts.first()
# users.first()

query = ("SELECT t.account_id FROM trans AS t, (SELECT account_id FROM trans GROUP BY account_id HAVING COUNT(trans_id) >= 2 ) new "
         + "WHERE t.account_id = new.account_id GROUP BY t.account_id HAVING count(t.type) >= 2")
results = sqlContext.sql(query)

# write data back to HDFS;
# repartition down to 10 partitions to reduce number of HDFS files written;
results.rdd.map(lambda p: str(p.account_id)).repartition(10).saveAsTextFile(sys.argv[2])


