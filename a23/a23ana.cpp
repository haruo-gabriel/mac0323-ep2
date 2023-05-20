Cel23* insere23(Cel23 *raiz, Palavra * pala, bool *cresceu){
    if(raiz == nullptr){
        Cel23 * raiz = cria23(pala);
        *cresceu = true;
        return raiz;
    }

    if(raiz->esq == nullptr && raiz->dir == nullptr && raiz->meio == nullptr){ // se é folha
        if(raiz->no2){ // so tem um item
            if(raiz->pala1->p == pala->p){
                raiz->pala1->qnt++;
            }
            if(raiz->pala1->p < pala->p){
                raiz->pala2 = pala;
                raiz->no2= false;
            }
            if(raiz->pala1->p > pala->p){
                raiz->pala2 = raiz->pala1;
                raiz->pala1 = pala;
                raiz->no2 = false;
            }
            *cresceu = false;
            return raiz;
        }
        else{// tres nó
            // vendo se é igual
            if(raiz->pala1->p == pala->p || raiz->pala2->p == pala->p){
                if(raiz->pala1->p == pala->p){
                    raiz->pala1->qnt++;
                }
                if(raiz->pala2->p == pala->p){
                    raiz->pala2->qnt++;
                }
                *cresceu = false;
                return raiz;
            }

            //vendo se a palavra é menor
            if(raiz->pala1->p > pala->p){
                Cel23 * maior = cria23(raiz->pala2);
                Cel23 * meio = cria23(raiz->pala1);
                
                raiz->pala1 = pala; // menor celula
                raiz->pala2 = nullptr;
                raiz->no2 = true;

                meio->meio = maior;
                meio->esq = raiz;

                *cresceu = true;
                return meio; // nova raiz;
            }
            else if(raiz->pala1->p < pala->p && raiz->pala2->p > pala->p){// se a palavra esta entre os dois valores
                Cel23 * meio = cria23(pala);
                Cel23 * maior = cria23(raiz->pala2);
                
                raiz->pala2 = nullptr;
                raiz->no2 = true;

                meio->esq = raiz;
                meio->meio = maior;
                *cresceu = true;
                return meio;
            }
            else{ // se a palavra é maior que as duas outras palavras
                Cel23 * meio = cria23(raiz->pala2);
                Cel23 * maior = cria23(pala);

                raiz->pala2 = nullptr;
                raiz->no2 = true;

                meio->esq = raiz;
                meio->meio = maior;

                *cresceu = true;
                return meio;
            }
        }
    }
    else{ // não é folha
        if(raiz->pala1->p > pala->p){ // se é menor que a palavra do n
            Cel23 * miau = insere23(raiz->esq, pala, cresceu);
            if(!*cresceu){
                raiz->esq = miau;
                return raiz;
            }
            else{
                if(raiz->no2){
                    raiz->pala2 = raiz->pala1;
                    raiz->pala1 = miau->pala1;

                    raiz->dir = raiz->meio;
                    raiz->esq = miau->esq;
                    raiz->meio = miau->meio;

                    raiz->no2 = false;
                    *cresceu = false;
                    //delete miau;
                    return raiz;
                }
                else{
                    Cel23 * menor = miau;
                    Cel23 * maior = cria23(raiz->pala2);

                    maior->esq = raiz->meio;
                    maior->meio = raiz->dir;
                    
                    raiz->pala2 = nullptr;
                    raiz->no2 = true;
                    raiz->esq = menor;
                    raiz->meio = maior;
                    raiz->dir = nullptr;
                    *cresceu = true;
                    return raiz;
                }
            }
        } else{
            if(raiz->no2){
                Cel23 * miau = insere23(raiz->meio, pala, cresceu);
                if(!*cresceu){
                    raiz->meio = miau;
                    return raiz;
                }
                else{
                    raiz->pala2 = miau->pala1;
                    raiz->no2 = false;
                    
                    raiz->dir = miau->meio;
                    raiz->meio = miau->esq;
                    
                    *cresceu = false;
                    //delete miau;
                    return raiz;
                }
            }
            else{
                
                if(raiz->pala2->p < pala->p){ // maior que a segunda palavra
                    Cel23* miau = insere23(raiz->dir, pala, cresceu);
                    if(!*cresceu){
                        raiz->dir = miau;
                        return raiz;
                    }
                    else{
                        Cel23 * maior = miau;
                        Cel23 * meio = cria23(raiz->pala2);

                        meio -> esq = raiz;
                        meio->meio = maior;

                        raiz->pala2 = nullptr;
                        raiz->dir = nullptr;

                        raiz->no2 = true;
                        *cresceu = true;
                        return meio;
                    }
 
                }else{
                    Cel23 *misu = insere23(raiz->meio, pala, cresceu);
                    if(!*cresceu){
                        raiz->meio = misu;
                        return raiz;
                    }
                    else{
                        Cel23 * meio = misu;
                        Cel23 * maior = cria23(raiz->pala2);
                        
                        maior->meio = raiz->dir;
                        maior->esq = meio->meio;

                        raiz->pala2 = nullptr;
                        raiz->dir = nullptr;
                        raiz->no2 = true;
                        raiz->meio = meio->esq;

                        meio -> esq = raiz;
                        meio->meio = maior;

                        *cresceu = true;
                        return meio;

                    }
                }
            }
        } 

    }
}