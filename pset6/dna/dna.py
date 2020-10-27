# CS50 Pset 6 DNA
from sys import argv
import csv

# Check user input
if len(argv) < 3:
    print("Usage: dna.py [databases] [sequences]")
    exit()

# Open DNA(sequences.txt) file and convert(line 15) data into string

with open(argv[2]) as dna_file:
    dna_read = csv.reader(dna_file)
    for row in dna_read:
        dna_list = row
dna = str(dna_list[0])

# Open CSV(database.csv) file and put data into a dictionary

with open(argv[1]) as people_file:
    people_list = [[val.strip() for val in r.split(",")] for r in people_file.readlines()]
(_, *header), *data = people_list
people_dict = {}
for row in data:
    key, *values = row
    people_dict[key] = {key: value for key, value in zip(header, values)}


# Count longest run in sequences(DNA)

check_a = 'AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG'
check_b = 'AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG'
checks_dict = {}
count = 0
# This zip function in the loop TOOK ME ALMOST 6 HOURS
for c, d in zip(check_a, check_b):
    while c in dna:
        count += 1
        c += str(d)
    checks_dict[d] = str(count)
    count = 0

# Match and find who it belongs it

finder = 0
for key in people_dict:
    match = {k: people_dict[key][k] for k in people_dict[key] if k in checks_dict and people_dict[key][k] == checks_dict[k]}
    if people_dict[key] == match:
        print(key)
        finder += 1

if finder == 0:
    print("No match")
