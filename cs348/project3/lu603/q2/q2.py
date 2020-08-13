##########
# q2.py
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

# table clien;
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

# try these commands in pyspark shell:
# lines.count()
# lines.first()
# parts.first()
# users.first()

query = (
    "SELECT DISTINCT c.client_id FROM client as c, disp as d WHERE c.client_id = d.client_id AND d.type <> 'OWNER'"
)
results = sqlContext.sql(query)

# write data back to HDFS;
# repartition down to 10 partitions to reduce number of HDFS files written;
results.rdd.map(lambda p: str(p.client_id)).repartition(10).saveAsTextFile(sys.argv[2])


