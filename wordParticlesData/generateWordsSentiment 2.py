#!/usr/bin/python

import sys,re
from textblob import TextBlob

file_in = str(sys.argv[1])
file_out = str(sys.argv[2])
filestream_in = open(file_in,'r+')
filestream_out = open(file_out,'w')

text = ''.join(filestream_in.readlines())

blob = TextBlob(text)
sentence_array = blob.sentences
word_array = blob.words

polarity_array = []
subjectivity_array = []
data_array = []

filestream_out.write('[')

for sentence in sentence_array:
	polarity_array.append(sentence.sentiment.polarity)
	subjectivity_array.append(sentence.sentiment.subjectivity)
	data_array.append(str(sentence))
	filestream_out.write(str(sentence))


filestream_out.write(']')
print polarity_array
print '\r'
print subjectivity_array
print data_array
print len(data_array)
print len(polarity_array)
filestream_in.close()
filestream_out.close()
