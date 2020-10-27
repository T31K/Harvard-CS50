input = input("Text: ")
input = input.lower()

# count words
words = 1 + input.count(" ")

# count letters
letters = 0
for i in range(len(input)):
    if input[i].isalpha():
        letters = letters + 1
        
# count sentences
punc = "!.?"
sentences = 0
for i in range(0, len(input)):
    if input[i] in punc:
        sentences = sentences + 1
 
# formula   
L = (letters / words) * 100 
S = (sentences / words) * 100 
index = round((0.0588 * L) - (0.296 * S) - 15.8)

if (index >= 1 and index <= 16):
    grade = "Grade"
    print('%s %d' % (grade, index))
elif index < 1:
    print("Before Grade 1\n")
elif index > 16:
    print("Grade 16+\n")
