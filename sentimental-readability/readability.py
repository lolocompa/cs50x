import cs50


def main():
    text = cs50.get_string("text: ")
    letters = count_letters(text)
    len_text = len(text)

    sentences= 0
    words = 1
    for letter in range(len_text):
        if letter == 32:
            words += 1
        elif letter == 46 or letter == 33 or letter == 63:
            sentences +=1

    wor = sentences / words
    l = letters / words * 100
    s = wor * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    grade = index + 0.5

    if grade > 16:
        print("grade 16+")
    elif grade < 1:
        print("before grade 1")
    else:
        print(f"grade {grade}")






def count_letters(text):
    length = len(text)
    puntuation = 0
    for let in range(length):
        let = let.lower()
        if let < 97:
            puntuation += 1
    let = length - puntuation
    return let

main()