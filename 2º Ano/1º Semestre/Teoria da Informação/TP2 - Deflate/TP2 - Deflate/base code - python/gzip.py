# Author: Marco Simoes
# Adapted from Java's implementation of Rui Pedro Paiva
# Teoria da Informacao, LEI, 2022

import sys
from huffmantree import HuffmanTree
import numpy as np

class GZIPHeader:
    ''' class for reading and storing GZIP header fields '''

    ID1 = ID2 = CM = FLG = XFL = OS = 0
    MTIME = []
    lenMTIME = 4
    mTime = 0

    # bits 0, 1, 2, 3 and 4, respectively (remaining 3 bits: reserved)
    FLG_FTEXT = FLG_FHCRC = FLG_FEXTRA = FLG_FNAME = FLG_FCOMMENT = 0

    # FLG_FTEXT --> ignored (usually 0)
    # if FLG_FEXTRA == 1
    XLEN, extraField = [], []
    lenXLEN = 2

    # if FLG_FNAME == 1
    fName = ''  # ends when a byte with value 0 is read

    # if FLG_FCOMMENT == 1
    fComment = ''  # ends when a byte with value 0 is read

    # if FLG_HCRC == 1
    HCRC = []

    def read(self, f):
        ''' reads and processes the Huffman header from file. Returns 0 if no error, -1 otherwise '''

        # ID 1 and 2: fixed values
        self.ID1 = f.read(1)[0]
        if self.ID1 != 0x1f: return -1  # error in the header

        self.ID2 = f.read(1)[0]
        if self.ID2 != 0x8b: return -1  # error in the header

        # CM - Compression Method: must be the value 8 for deflate
        self.CM = f.read(1)[0]
        if self.CM != 0x08: return -1  # error in the header

        # Flags
        self.FLG = f.read(1)[0]

        # MTIME
        self.MTIME = [0] * self.lenMTIME
        self.mTime = 0
        for i in range(self.lenMTIME):
            self.MTIME[i] = f.read(1)[0]
            self.mTime += self.MTIME[i] << (8 * i)

        # XFL (not processed...)
        self.XFL = f.read(1)[0]

        # OS (not processed...)
        self.OS = f.read(1)[0]

        # --- Check Flags
        self.FLG_FTEXT = self.FLG & 0x01
        self.FLG_FHCRC = (self.FLG & 0x02) >> 1
        self.FLG_FEXTRA = (self.FLG & 0x04) >> 2
        self.FLG_FNAME = (self.FLG & 0x08) >> 3
        self.FLG_FCOMMENT = (self.FLG & 0x10) >> 4

        # FLG_EXTRA
        if self.FLG_FEXTRA == 1:
            # read 2 bytes XLEN + XLEN bytes de extra field
            # 1st byte: LSB, 2nd: MSB
            self.XLEN = [0] * self.lenXLEN
            self.XLEN[0] = f.read(1)[0]
            self.XLEN[1] = f.read(1)[0]
            self.xlen = self.XLEN[1] << 8 + self.XLEN[0]

            # read extraField and ignore its values
            self.extraField = f.read(self.xlen)

        def read_str_until_0(f):
            s = ''
            while True:
                c = f.read(1)[0]
                if c == 0:
                    return s
                s += chr(c)

        # FLG_FNAME
        if self.FLG_FNAME == 1:
            self.fName = read_str_until_0(f)

        # FLG_FCOMMENT
        if self.FLG_FCOMMENT == 1:
            self.fComment = read_str_until_0(f)

        # FLG_FHCRC (not processed...)
        if self.FLG_FHCRC == 1:
            self.HCRC = f.read(2)

        return 0


class GZIP:
    ''' class for GZIP decompressing file (if compressed with deflate) '''

    gzh = None
    gzFile = ''
    fileSize = origFileSize = -1
    numBlocks = 0
    f = None

    bits_buffer = 0
    available_bits = 0

    def __init__(self, filename):
        self.gzFile = filename
        self.f = open(filename, 'rb')
        self.f.seek(0, 2)
        self.fileSize = self.f.tell()
        self.f.seek(0)

    def decompress(self):
        ''' main function for decompressing the gzip file with deflate algorithm '''

        numBlocks = 0

        # get original file size: size of file before compression
        origFileSize = self.getOrigFileSize()
        print(origFileSize)

        # read GZIP header
        error = self.getHeader()
        if error != 0:
            print('Formato invalido!')
            return

        # show filename read from GZIP header
        print(self.gzh.fName)

        # MAIN LOOP - decode block by block
        BFINAL = 0
        janela = []
        while not BFINAL == 1:

            BFINAL = self.readBits(1)

            BTYPE = self.readBits(2)
            if BTYPE != 2:
                print('Error: Block %d not coded with Huffman Dynamic coding' % (numBlocks + 1))
                return
            # --- STUDENTS --- ADD CODE HERE

            # Exercicio1

            HLIT, HDIST, HCLEN = self.readBlockFormat()
            print("HLIT:", HLIT)
            print("HDIST:", HDIST)
            print("HCLEN:", HCLEN)

            # Exercicio2
            hclen_codeslenght = self.readCodeLengths(HCLEN)
            print(hclen_codeslenght)

            # Exercicio3
            tenta = self.exercicio3(hclen_codeslenght)
            print(tenta)

            array_em_bin = self.transforma_em_bin(tenta, hclen_codeslenght)
            print(array_em_bin)

            self.inserir_arvore(array_em_bin)

            # Exercicio 4
            HLIT += 257
            guarda = self.exercicio4_5(HLIT, array_em_bin)
            print(guarda)

            # Exercicio 5
            HDIST += 1
            comp_distancias = self.exercicio4_5(HDIST, array_em_bin)
            print("\n\n\n hhhh \n\n")
            print(comp_distancias)

            # eX 6 copi
            # code_literal, code_dist, treeCodeLiterais, treeCodeDist = self.exercicio6(comp_distancias,guarda)

            # Exercicio 6
            arvore_huff_lit = self.exercicio_6_literais(guarda)

            arvore_huff_literais = self.inserir_arvore(arvore_huff_lit)

            print("\n Arvore 2 \n")

            arvore_huff_dis = self.exercicio_6_literais(comp_distancias)

            arvore_huff_dist = self.inserir_arvore(arvore_huff_dis)

            # exercicio 7
            dados = self.exercicio7(arvore_huff_literais,arvore_huff_dist, janela)

            #exercicio 8
            self.exercicio8(dados)

            # adiciona à janela os valores de dados do bloco atual
            # é usado para caso o ficheiro tenha mais do que um bloco e precise de ler valores do bloco anterior
            # a janela só necessita de ter tamanho 32768 pois é o máximo de distancia que o LZ77 pode recuar
            janela += dados
            if len(janela) >= 32768:
                # caso a janela tenha mais do que 32768 elementos, DAMOS UM SLICE PARA FICAR APENAS COM OS 32768 ÚLTIMOS
                janela = janela[-32768:]

            # update number of blocks read
            numBlocks += 1

        # close file

        self.f.close()
        print("End: %d block(s) analyzed." % numBlocks)

    def getOrigFileSize(self):
        ''' reads file size of original file (before compression) - ISIZE '''

        # saves current position of file pointer
        fp = self.f.tell()

        # jumps to end-4 position
        self.f.seek(self.fileSize - 4)

        # reads the last 4 bytes (LITTLE ENDIAN)
        sz = 0
        for i in range(4):
            sz += self.f.read(1)[0] << (8 * i)

        # restores file pointer to its original position
        self.f.seek(fp)

        return sz

    def getHeader(self):
        ''' reads GZIP header'''

        self.gzh = GZIPHeader()
        header_error = self.gzh.read(self.f)
        return header_error

    def readBits(self, n, keep=False):
        ''' reads n bits from bits_buffer. if keep = True, leaves bits in the buffer for future accesses '''

        while n > self.available_bits:
            self.bits_buffer = self.f.read(1)[0] << self.available_bits | self.bits_buffer
            self.available_bits += 8

        mask = (2 ** n) - 1
        value = self.bits_buffer & mask

        if not keep:
            self.bits_buffer >>= n
            self.available_bits -= n

        return value

    # Exercicio 1
    def readBlockFormat(self):
        #Le o numero de bits a associados ao formato do bloco // HLIT- 5 bits && HDIST - 5 bits && HCLEN- 5 bits
        HLIT = self.readBits(5)
        HDIST = self.readBits(5)
        HCLEN = self.readBits(4)

        return HLIT, HDIST, HCLEN

    # Exercicio2
    def readCodeLengths(self, hclen):
        code_lengths_order = [16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15]

        code_lengths = np.zeros(len(code_lengths_order), dtype=int)  # Inicializa um array para armazenar os comprimentos de código

        for i in range(hclen + 4):
            code_lengths[code_lengths_order[i]] = self.readBits(3)  # Lê os comprimentos de código de 3 bits

        return code_lengths

    # Exercicio 3

    def exercicio3(self, n_array):
        # Passo 1 (DOC 2)

        # Passo 1:
        numeros = []
        for i in range(len(n_array)):
            if n_array[i] not in numeros:
                numeros.append(n_array[i])
                numeros = sorted(numeros)
                maximo = max(numeros)

        # Passo 2:
        numero_ocorrencias = np.bincount(n_array)
        numero_ocorrencias[0] = 0

        prox_codigo = np.zeros(maximo + 1, int)

        codigo = 0

        for bits in range(1, maximo + 1):
            codigo = (codigo + numero_ocorrencias[bits - 1]) * 2
            prox_codigo[bits] = codigo

        # Passo 3:
        codigo_arvore = np.full(len(n_array), -1)

        for n in range(len(n_array)):
            comp = n_array[n]
            if comp != 0:
                codigo_arvore[n] = prox_codigo[comp]
                prox_codigo[comp] += 1

        return codigo_arvore

    # Exercicio 3 -Transformar array em binario

    def transforma_em_bin(self, array, array_comprimentos):
        novo_array = []

        for decimal, comprimento in zip(array, array_comprimentos):
            if decimal == -1:
                novo_array.append('')
            elif decimal == 0:
                numero = "0"
                while len(numero) < comprimento:
                    numero = "0" + numero
                novo_array.append(numero)
            else:
                numero_bin = ""
                while decimal > 0:
                    res = decimal & 1
                    numero_bin = str(res) + numero_bin
                    decimal >>= 1
                if len(numero_bin) < comprimento:
                    while len(numero_bin) < comprimento:
                        numero_bin = '0' + numero_bin
                novo_array.append(numero_bin)
        return novo_array

    # Exercicio 4
    def inserir_arvore(self, codigos):
        arvore_huffman = HuffmanTree()
        for i in range(len(codigos)):
            if codigos[i] != '':
                arvore_huffman.addNode(codigos[i], i, True)
        return arvore_huffman

    def exercicio4_5(self, alfabeto, codigo_arvore):
        code = []
        count = 0
        read_Bits1 = ""

        while alfabeto != count:
            read_Bits1 = read_Bits1 + str(self.readBits(1))
            if read_Bits1 in codigo_arvore:
                pos = codigo_arvore.index(read_Bits1)

                if pos == 16:
                    num_vezes = self.readBits(2)
                    comp_anterior = code[len(code) - 1]
                    for i in range(num_vezes + 3):
                        code.append(comp_anterior)
                        count = count + 1
                elif pos == 17:
                    num_vezes = self.readBits(3)
                    for i in range(num_vezes + 3):
                        code.append(0)
                        count = count + 1

                elif pos == 18:
                    num_vezes = self.readBits(7)
                    for i in range(num_vezes + 11):
                        code.append(0)
                        count = count + 1
                else:
                    code.append(pos)
                    count = count + 1

                read_Bits1 = ""

        return code

    # EXERCICIO 6

    def exercicio_6_literais(self, codigo):

        converte = self.exercicio3(codigo)

        converte_em_bin = self.transforma_em_bin(converte, codigo)
        return converte_em_bin

    def exercicio_6_distancias(self, codigo):
        converte = self.exercicio3(codigo)
        converte_em_bin = self.transforma_em_bin(converte, codigo)
        return converte_em_bin

    #exercicio7
    def exercicio7(self, Hlit_tree, Hdist_tree, window):
        #Doc 2
        comprimentos = {265: 11, 266: 13, 267: 15, 268: 17,
                   269: 19, 270: 23, 271: 27, 272: 31, 273: 35, 274: 43, 275: 51,
                   276: 59, 277: 67, 278: 83, 279: 99, 280: 115, 281: 131, 282: 163, 283: 195, 284: 227, 285: 258}



        distancias = {4: 5, 5: 7, 6: 9, 7: 13, 8: 17, 9: 25, 10: 33, 11: 49, 12: 65, 13: 97, 14: 129, 15: 193, 16: 257,
                     17: 385, 18: 513, 19: 769, 20: 1025, 21: 1537, 22: 2049, 23: 3073, 24: 4097, 25: 6145, 26: 8193,
                     27: 12289, 28: 16385, 29: 24577}


        first_len = len(window)  # <- Tamanho da window guardado pois esta pode entrar na função com valores, e estes tem de ser retirados no final para não se repetirem dados ->
        end_of_block = False
        posicao = len(window)
        while not end_of_block:
            lit_len_node = self.exercicio7_bit_por_bit(Hlit_tree)

            # verficiamos se o valor lido na arvore dos literais/comprimentos é um literal ou um comprimento
            # ou o fim do bloco
            if lit_len_node < 256:
                # se for um literal adicionamos a window e repetimos
                window.append(lit_len_node)
                posicao += 1
            elif lit_len_node == 256:
                end_of_block = True

            else:
                # se for comprimento, calculamos o valor do comprimento usando o dicionario dos comprimentos
                # lendo os bits necessarios para chegar a essa valor
                if 257 <= lit_len_node <= 264:
                    length = lit_len_node - 257 + 3
                elif lit_len_node == 285:
                    length = 258
                else:
                    bits = ( lit_len_node - 261) // 4  # <- Resultado é a divisão inteira »»»
                    length = comprimentos[lit_len_node] + self.readBits(bits)  # <- Define o comprimento com auxílio das tabela acima de valores predefenidos ->

                # como temos um comprimentos tambem temos de ter distamcias
                # vamos ler os proximos bits para entrar na arvore de huffman das distancias e obter um valor
                dist_node = self.exercicio7_bit_por_bit(Hdist_tree)

                # a partir desse valor e do dicionario das distancias calculamos o valor da distancia a recuar
                if 0 <= dist_node <= 3:
                    distance = 1 + dist_node
                else:
                    bits = (dist_node // 2) - 1
                    if dist_node > 27:
                        bits = 13
                    distance = distancias[dist_node] + self.readBits(bits)

                # copiamos os valores que estao à distância calculada do fim da data para a window de informacao
                for i in range(length):
                    window.append(window[posicao - distance + i])
                posicao += length
                # ----------------------------

        # como usamos uma window para caso haja mais do que um bloco podermos ler os valores anterior,
        # temos de retirar esses valores anteriores para nao repetirmos informacao
        window = window[first_len -len(window):]

        return window

    def exercicio7_bit_por_bit(self, huffman_tree):
        # A funcao recebe uma arvore e analisa bit por bit
        # Verifica a existencia de um match com um codigo de huffman
        # é devolvido o node da arvore de huffman

        found = False
        node = -1

        while not found:

            code = str(self.readBits(1))
            node = huffman_tree.nextNode(code)

            if node != -1 and node != -2:
                found = True

        huffman_tree.resetCurNode()
        return node


    def exercicio8(self, data):
        fnome = self.gzFile[:-3]

        with open(fnome, "ab") as ficheiro:
            ficheiro.write(bytes(data))
            #for i in data:
             #   ficheiro.write(chr(i))


if __name__ == '__main__':

    # gets filename from command line if provided
    fileName = "sample_image.jpeg.gz"
    if len(sys.argv) > 1:
        fileName = sys.argv[1]

    # decompress file
    gz = GZIP(fileName)
    gz.decompress()


