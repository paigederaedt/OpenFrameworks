#!/usr/bin/python

import sys,csv,numpy as np
from textblob import TextBlob

file_in = str(sys.argv[1])
filestream_in = open(file_in,'r+')

text = ''.join(filestream_in.readlines())

blob = TextBlob(text)
sentence_array = blob.sentences
word_array = blob.words
print sentence_array
#print word_array

polarity_array = []
subjectivity_array = []
for sentence in sentence_array:
#for word in word_array:
	polarity_array.append(sentence.sentiment.polarity)
	#polarity_array.append(word.sentiment.polarity)
	subjectivity_array.append(sentence.sentiment.subjectivity)
	#subjectivity_array.append(word.sentiment.subjectivity)

print polarity_array;
print subjectivity_array;
filestream_in.close()
