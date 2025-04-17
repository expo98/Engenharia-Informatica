from curses.textpad import Textbox
import string

def codificacao(text, shift, alphabets):

    def shift_alphabet(alphabet):
        return alphabet[shift:] + alphabet[:shift]

    shifted_alphabets = tuple(map(shift_alphabet, alphabets))
    final_alphabet = ''.join(alphabets)
    final_shifted_alphabet = ''.join(shifted_alphabets)
    table = str.maketrans(final_alphabet, final_shifted_alphabet)
    return text.translate(table)


chave = input(str("Introduz uma frase para codificar: "))
print("Introduz uma distância para codificação: ")
dist = int(input())
print(codificacao(chave, dist, [string.ascii_lowercase, string.ascii_uppercase, string.punctuation]))