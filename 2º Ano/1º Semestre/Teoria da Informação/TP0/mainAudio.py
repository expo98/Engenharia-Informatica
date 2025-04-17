#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 29 14:27:33 2023

@author: miguempereira
"""

from scipy.io import wavfile
import sounddevice as sd
import matplotlib.pyplot as plt

def apresentarInfo(nomeFicheiro, fs, nrBitsQuant):
    print("Informações do ficheiro")
    print("Nome do ficheiro " + nomeFicheiro)
    print("Taxa de amostragem : ", fs/1000," kHz")
    print("Quantização: ", nrBitsQuant, "Bits")

def visualizacaoGrafica(data, fs):
    Tinicial=0
    Ts=1/fs
    Tfim=(data.shape[0]-1) * Ts
    
        
    
    
def main():
        
    [fs,data] = wavfile.read("drumloop.wav")
    
    sd.play(data,fs,blocking=True)
    status = sd.wait()
    
    apresentarInfo("drumloop.wav", fs, data.itemsize*8)
    
    
if __name__ == "__main__":
    main()

