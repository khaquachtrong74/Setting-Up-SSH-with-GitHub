'''
PURPOSE:    BUILD TF-IDF FUNCTION
FUNCTION:   COUNTS FREQUENCY WORDS ON DOCUMENTS
            RETURN VALUE FREQ
'''
import re
from collections import Counter
import string
import numpy as np
def sum_list(set_words):
    total = 0
    ''''
    Function to sum weight in word (frequency)
    '''
    for weight in set_words:
        total += weight
    return total
def words_count(document):
    '''
    Function Count Words on document
    '''
    words = re.findall(r'\b\w+\b', document.lower())

    counter_words = Counter(words)
    set_word = set([word for word in words])
    list_weight = [counter_words[weight] for weight in set_word]
    return words, sum_list(list_weight), set_word

'''Function to caculate Tf with word'''
def caculate_Tf(document, word):
    word = word.lower()
    words, total, set_word = words_count(document)
    word_weight = Counter(words)[word]
    return (word_weight/total)
    
'''Function to visualize frequency words'''
def matrix_frequency_words(document):
    words, total, set_word = words_count(document)
    matrix = np.zeros((len(set_word),len(words)))
    list_set_word = list(set_word)
    for i, word in enumerate(list_set_word):
        tmp_words = words.copy()
        for j, w in enumerate(tmp_words):
            if w == word:
                matrix[i][j] = caculate_Tf(document, w)
            else:
                matrix[i][j] = 0
    return matrix
if __name__ == '__main__':
    document = "Thế nào, nào có làm có được không,!nào có.."
    tmp, total, set_word = words_count(document)    
    print(tmp)
    print(total)
    print(set_word)
    matrix_word = matrix_frequency_words(document)
    print(matrix_word)
