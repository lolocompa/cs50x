import cs50


def main():
    text = cs50.get_string("text: ")
    letters = count_letters(text)
    len_text = len(text)

    sentences= 0
    words = 1
    for letter in text:
        if letter == ' ':
            words += 1
        elif letter == '.' or letter == '?' or letter == '!':
            sentences +=1

    wor = sentences / words
    l = letters / words * 100
    s = wor * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    grade = round(index)

    if grade > 16:
        print("grade 16+")
    elif grade < 1:
        print("before grade 1")
    else:
        print(f"Grade {grade}")






def count_letters(text):
    length = len(text)
    puntuation = 0
    for let in text:
        if let.lower() < 'a':
            puntuation += 1
    lete = length - puntuation
    return lete

main()