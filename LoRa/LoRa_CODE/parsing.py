# import modules
import numpy as np
import os
from parse import *
import json

# set directory
file_name = 'log.txt'

# open file and print it as an example
file_opened = open(file_name)
line=file_opened.readline()
line = json.loads(line[line.find('{'):])
print(line)

temp=line['payload_fields']['temperature_1']
soil=line['payload_fields']['luminosity_3']
hum=line['payload_fields']['relative_humidity_2']
time=line['metadata']['time']

with open("parselog.txt","a") as text_file:
    text_file.write('time:{},'.format(time))
    text_file.write('luminosity_3:{},'.format(soil))
    text_file.write('relative_humidity:{},'.format(hum))
    text_file.write('temperature:{}'.format(temp))

