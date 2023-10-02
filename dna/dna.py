import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("only two command line arguments")
        sys.exit()

    #read data into memory
    people = []

    file = open(sys.argv[1], "r")
    file_reader = csv.DictReader(file)

    for row in file_reader:
        people.append(row)

    # TODO: Read DNA sequence file into a variable
    dna = []

    dna_file = open(sys.argv[2], "r")
    dna_reader = dna_file.read()

    for char in dna_reader:
        dna.append(char)


    # TODO: Find longest match of each STR in DNA sequence

    sequences = []
    element = people[0]
    for e in element:
        sequences.append(e)
    sequences.remove('name')


    count = []
    for sequence in sequences:
        result = longest_match(dna_reader, sequence)
        count.append(result)



    # TODO: Check database for matching profiles

    length = len(sequences)
    for person in people:
        check = 0
        for r in range(length):
            if count[r] == int(person[f"{sequences[r]}"]):
                check += 1
        if check == length:
            name = person["name"]
            print(f"match with {name}")
            sys.exit()

    print("no match")






def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
