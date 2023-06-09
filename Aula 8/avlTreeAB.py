# Código no material complementar do curso do prof. André Backes no site Linguagem C Descomplicada
# Em https://www.facom.ufu.br/~backes/wordpress/proj_arvore_avl.py

import copy
import math

class NO:
    def __init__(self,info):
        self.info = info
        self.altura = 0
        self.esq = None
        self.dir = None
        
class ArvAVL:
    def __init__(self):
        self.__raiz = None

    def __alturaNO(self, no):
        if(no == None):
            return -1
        else:
            return no.altura

    def __fatorBalanceamento_NO(self, no):
        return abs(self.__alturaNO(no.esq) - self.__alturaNO(no.dir))    

    def __maior(self, x, y):
        if(x > y):
            return x
        else:
            return y

    def __RotacaoLL(self, A):
        # print('RotacaoLL: ',A.info);
        B = A.esq
        A.esq = B.dir
        B.dir = A
        A.altura = self.__maior(self.__alturaNO(A.esq),self.__alturaNO(A.dir)) + 1
        B.altura = self.__maior(self.__alturaNO(B.esq),A.altura) + 1
        #A = B
        return B

    def __RotacaoRR(self, A):
        # print('RotacaoRR: ',A.info);
        B = A.dir
        A.dir = B.esq
        B.esq = A
        A.altura = self.__maior(self.__alturaNO(A.esq),self.__alturaNO(A.dir)) + 1
        B.altura = self.__maior(self.__alturaNO(B.dir),A.altura) + 1
        #A = B
        return B

    def __RotacaoLR(self, A):
        A.esq = self.__RotacaoRR(A.esq)
        A = self.__RotacaoLL(A)
        return A
        
    def __RotacaoRL(self, A):
        A.dir = self.__RotacaoLL(A.dir)
        A = self.__RotacaoRR(A)
        return A

    def __insereNO(self,atual,valor):
        if(atual == None): # Ã¡rvore vazia ou nÃ³ folha
            novo = NO(valor)
            return novo
        else:
            if(valor < atual.info):
                atual.esq = self.__insereNO(atual.esq, valor)
                if(self.__fatorBalanceamento_NO(atual) >= 2):
                    if(valor < atual.esq.info):
                        atual = self.__RotacaoLL(atual)
                    else:
                        atual = self.__RotacaoLR(atual)
            else:
                atual.dir = self.__insereNO(atual.dir, valor)
                if(self.__fatorBalanceamento_NO(atual) >= 2):
                    if(valor > atual.dir.info):
                        atual = self.__RotacaoRR(atual)
                    else:
                        atual = self.__RotacaoRL(atual)

            atual.altura = self.__maior(self.__alturaNO(atual.esq),self.__alturaNO(atual.dir)) + 1
            return atual                

    def insere(self, valor):
        if(self.busca(valor)):
            return False #valor jÃ¡ existe na Ã¡rvore
        else:
            self.__raiz = self.__insereNO(self.__raiz, valor)
            return True

    def busca(self, valor):
        if(self.__raiz == None):
            return False

        atual = self.__raiz
        while(atual != None):
            if(valor == atual.info):
                return True
            
            if(valor > atual.info):
                atual = atual.dir
            else:
                atual = atual.esq
        
        return False

    def __procuraMenor(self, atual):
        no1 = atual
        no2 = atual.esq
        while(no2 != None):
            no1 = no2
            no2 = no2.esq

        return no1

    def __removeNO(self, atual, valor):
        if(atual.info == valor): #achou o nÃ³ a ser removido
            if(atual.esq == None or atual.dir == None): # nÃ³ tem 1 filho ou nenhum
                if(atual.esq != None):
                    atual = atual.esq
                else:
                    atual = atual.dir
                
            else: # nÃ³ tem 2 filhos
                temp = self.__procuraMenor(atual.dir)
                atual.info = temp.info
                atual.dir = self.__removeNO(atual.dir, atual.info)
                if(self.__fatorBalanceamento_NO(atual) >= 2):
                    if(self.__alturaNO(atual.esq.dir) <= self.__alturaNO(atual.esq.esq)):
                        atual = self.__RotacaoLL(atual)
                    else:
                        # print('ok')
                        atual = self.__RotacaoLR(atual)
                        
            if(atual != None):
                atual.altura = self.__maior(self.__alturaNO(atual.esq),self.__alturaNO(atual.dir)) + 1

        else:# procura o nÃ³ a ser removido
            if(valor < atual.info):
                atual.esq = self.__removeNO(atual.esq, valor)
                if(self.__fatorBalanceamento_NO(atual) >= 2):
                    if(self.__alturaNO(atual.dir.esq) <= self.__alturaNO(atual.dir.dir)):
                        atual = self.__RotacaoRR(atual)
                    else:
                        atual = self.__RotacaoRL(atual)                        
            else:
                atual.dir = self.__removeNO(atual.dir, valor)
                if(self.__fatorBalanceamento_NO(atual) >= 2):
                    if(self.__alturaNO(atual.esq.dir) <= self.__alturaNO(atual.esq.esq)):
                        atual = self.__RotacaoLL(atual)
                    else:
                        atual = self.__RotacaoLR(atual)

            atual.altura = self.__maior(self.__alturaNO(atual.esq),self.__alturaNO(atual.dir)) + 1

        return atual    
    
    def remove(self, valor):        
        if(self.__raiz == None or not self.busca(valor)):
            return False #Ã¡rvore vazia ou valor nÃ£o existe na Ã¡rvore
        else:
            self.__raiz = self.__removeNO(self.__raiz, valor)
            return True    

    def __preOrdem(self,raiz):
        if(raiz != None):
            # print(raiz.altura,') ',raiz.info)
            self.__preOrdem(raiz.esq)
            self.__preOrdem(raiz.dir)

    def preOrdem(self):
        if(self.__raiz != None):
            self.__preOrdem(self.__raiz)

    def __emOrdem(self,raiz):
        if(raiz != None):            
            self.__emOrdem(raiz.esq)
            # print(raiz.altura,') ',raiz.info)
            self.__emOrdem(raiz.dir)

    def emOrdem(self):
        if(self.__raiz != None):
            self.__emOrdem(self.__raiz)
        
    def __posOrdem(self,raiz):
        if(raiz != None):            
            self.__posOrdem(raiz.esq)            
            self.__posOrdem(raiz.dir)
            # print(raiz.altura,') ',raiz.info)

    def posOrdem(self):
        if(self.__raiz != None):
            self.__posOrdem(self.__raiz)

    # Adaptação para calcular alturas das subárvores
    
    def altura_subarvores(self):
        if self.__raiz is None:
            return None
        
        return self.__altura_subarvores(self.__raiz)

    def __altura_subarvores(self, no):
        if no is None:
            return [0, 0]
        
        altura_esq = no.esq.altura if no.esq else -1
        altura_dir = no.dir.altura if no.dir else -1
        return [altura_esq, altura_dir]
