from posixpath import split
import pandas as pd

MAX_ITEMS_PER_FILE = 500
PATH = "data/data-"
SRC_PATH = "data/data.csv"

df = pd.read_csv(SRC_PATH)
count = 0
pre_count = -1
count_file = 0

for i in range(len(df)):
    if (count % MAX_ITEMS_PER_FILE == 0 and count != pre_count):
        textFile = open(PATH + str(count_file) +
                        ".txt", "w", encoding="utf-8")
        count_file += 1

    pre_count = count
    if (df.iloc[i, 0].find(" ") == -1):
        count += 1
        textPerLine = str(df.iloc[i, 0]) + str("|") + \
            str(df.iloc[i, 1]) + str("|") + \
            str(df.iloc[i, 2]) + str("|") + "\n"
        textFile.write(textPerLine)
