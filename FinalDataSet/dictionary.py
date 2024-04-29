####### GENERATING WORDS
from english_words import get_english_words_set
import random

# Get a set of English words
english_words = get_english_words_set(["web2"], lower=True)

# Generate 1000 unique words
unique_words = random.sample(english_words, 100000)

# Write the words to a text file
with open("dataSet10.csv", "w") as file:
    for word in unique_words:
        file.write(word + "\n")

print("Data written to dataSet1.csv")

#Link to google collab  for graphs : https://colab.research.google.com/drive/1jhIAV8MWF5jg8dO69SwQlPIUF_NCThP1?usp=sharing