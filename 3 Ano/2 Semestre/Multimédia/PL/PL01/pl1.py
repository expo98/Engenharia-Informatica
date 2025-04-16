import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as clr

cmRed = clr.LinearSegmentedColormap.from_list('red', [(0,0,0), (1,0,0)])
cmBlue = clr.LinearSegmentedColormap.from_list('blue', [(0,0,0), (0,0,1)])
cmGreen = clr.LinearSegmentedColormap.from_list('green', [(0,0,0), (0,1,0)])
cmGray = clr.LinearSegmentedColormap.from_list('gray', [(0,0,0), (1,1,1)])


def showImage(img, title, cm = None):
    plt.figure()
    plt.imshow(img, cm)
    plt.axis('off')
    plt.title(title)
    plt.show()


def encoder(img):
    R = img[:,:,0]
    G = img[:,:,1]
    B = img[:,:,2]
    return R, G, B

def decoder(R, G, B):
    nl, nc = R.shape
    imgRec = np.zeros((nl, nc, 3), dtype = np.uint8)
    imgRec[:,:,0] = R
    imgRec[:,:,1] = G
    imgRec[:,:,2] = B

    return imgRec

def encoderPadding(RGB):
    l,c = RGB.shape
    l_pad = 32 - (l % 32)  if l % 32 != 0 else 0
    c_pad = 32 - (c % 32)  if c % 32 != 0 else 0


    linhasRepetidas = np.repeat(RGB[-1:,:], l_pad, axis=0)

    imgPadded = np.vstack((RGB, linhasRepetidas))

    colunasRepetidas = np.repeat(imgPadded[:,-1:], c_pad, axis=1)

    imgPadded = np.hstack((imgPadded, colunasRepetidas))

    return imgPadded

def decoderPadding(imgPadded, line, coll):
    img = imgPadded[:line, :coll]
    return img

def RGBtoYCbCr(R, G, B):
    ycbrMatrix = np.array([[0.299, 0.587, 0.114], [-0.168736, -0.3313264, 0.5], [0.5, -0.418688, -0.081312]])
    rgbMatrix = np.array([R, G, B])

    print(rgbMatrix.shape)
    print(ycbrMatrix.shape)
    YCbCr = np.dot(ycbrMatrix, rgbMatrix)
    YCbCr = np.sum(YCbCr, np.array([0, 128, 128]))
    return YCbCr

def YCbCrtoRGB(YCbCr):
    RGB = np.linalg.inv(YCbCr)

    
    return RGB

def main():
    fName = "./imagens/airport.bmp"
    img = plt.imread(fName)
    #showImage(img, fName)
    print(img.shape)
    l, c, _ = img.shape
    

    R, G, B = encoder(img)
    imgRec = decoder(R,G,B)

    imgPad = encoderPadding(R)
    showImage(imgPad, "Imagem com padding", cmRed)

    imgDepad = decoderPadding(imgPad, l, c)
    showImage(imgDepad, "Imagem sem padding", cmRed)

    imgPad = encoderPadding(G)
    showImage(imgPad, "Imagem com padding", cmGreen)

    imgDepad = decoderPadding(imgPad, l, c)
    showImage(imgDepad, "Imagem sem padding", cmGreen)

    imgPad = encoderPadding(B)
    showImage(imgPad, "Imagem com padding", cmBlue)

    imgDepad = decoderPadding(imgPad, l, c)
    showImage(imgDepad, "Imagem sem padding", cmBlue)

    #showImage(R, "Red", cmRed)

    #showImage(B, "Blue", cmBlue)

    #showImage(G, "Green", cmGreen)

    #showImage(R, "Gray", cmGray)

    """showImage(imgRec, "Imagem descodificada")"""

    print(RGBtoYCbCr(R,G,B).shape)


    #ponto 4
    #no padding para saber quantas linhas adicionar, fazer o resto da divisão inteira entre o numero de linhas e 32 e subtrair o resultado de 32
    #usar o np.repeat para repetir as linhas e colunas da imagem até fazer os multiplos de 32
    #usar o np.vstack e np.hstack para adicionar as linhas e colunas à imagem

    #ponto 5
    #YCbCr Y = 0.3R + 0.6G + 0.1B
    #Usar a matriz de transformação para passar de RGB para YCbCr e meter os dados em float
    #Y = | 0.299    0.587    0.114 | | R | + | 0 |
    #CB =|-0.1687  -0.3313   0.5   | | G | + | 128 |
    #CR =| 0.5     -0.4187  -0.0813| | B | + | 128 |

    #para calcular os RGB não usamos a matriz dos slides mas usamos ti = np.linalg.inv(t), meter em float


   

if __name__ == '__main__':
    main()