
import numpy as np
import csv as csv
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import GridSearchCV
import sklearn.metrics
from sklearn.cross_validation import train_test_split

import nltk
nltk.download()
data = pd.read_csv("fin2.csv" , sep = ",", encoding='utf-8')

import sys
reload(sys)
sys.setdefaultencoding('utf-8')


del data["Source"]
del data["Type"]
del data["Location"]
del data["Mentions_count"]

blacklist = []

with open("blacklist.txt", "r") as fl:
	for line in fl:
		for word in line.split():
			blacklist.append(word)


target = data.Label
################################################ word level analysis with stemming ########################
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem.porter import PorterStemmer

Text_field = data["Text"]

i = 0

text_label = []

for field in Text_field:
	tokens = word_tokenize(field)

	tokens = [w.lower() for w in tokens]

	words = [word for word in tokens if word.isalpha()]

	stop_words = stopwords.words('english')
	words = [w for w in words if not w in stop_words]

	porter = PorterStemmer()
	stemmed = [porter.stem(word) for word in words]

	for test_word in stemmed:
		flag = 0
		for bl_word in blacklist:
			if test_word == bl_word:
				flag = 1
				break
		if flag is 1:
			break
		
	if flag is 1:
		text_label.append(1)
	else:
		text_label.append(0)

	i = i + 1 


print len(Text_field)
print len(text_label)
data["Text_label"] = text_label
########################################   Random Forest   ###########################
data = data.dropna()
predictors = data[['Retweet_count' , 'Favorite_count' , 'Hashtags_count','Urls_count','Media_count','Symbols_count'
                  ,'Possibly_sensitive','URL','Description_len','Verified','Ff_ratio','Follower_count','Friend_count','Statuses_count'
                ,'Favourites_count','Listed_count','Account_age','Default_profile','Default_profile_image']]


pred_train , pred_test, tar_train , tar_test = train_test_split(predictors , target , test_size = .4)

classifier = RandomForestClassifier(n_estimators = 25)
classifier = classifier.fit(pred_train , tar_train)

predictions = classifier.predict(pred_test)

sklearn.metrics.confusion_matrix(tar_test , predictions)

print sklearn.metrics.accuracy_score(tar_test , predictions)

print sklearn.metrics.f1_score(tar_test , predictions)
