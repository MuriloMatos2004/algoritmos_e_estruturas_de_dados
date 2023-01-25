bool is_abb_aux(NO *raiz){
    if(raiz == NULL) return true;

    if(raiz->dir == NULL && raiz->esq == NULL)
        return true;

    if(raiz->dir != NULL){
        if(item_get_chave(raiz->item) > item_get_chave(raiz->dir->item))
            return false;
        if(raiz->dir->esq != NULL && item_get_chave(raiz->item) > item_get_chave(raiz->dir->esq->item))
            return false;
    }
    if(raiz->esq != NULL){
        if(item_get_chave(raiz->item) < item_get_chave(raiz->esq->item))
            return false;
        if(raiz->esq->dir != NULL && item_get_chave(raiz->item) < item_get_chave(raiz->esq->dir->item))
            return false;
    }
    
    bool valor_1 = is_abb_aux(raiz->esq);
    bool valor_2 = is_abb_aux(raiz->dir);

    if(valor_1 == true && valor_2 == true)
        return true;
    return false;
}

bool is_abb(AB *T){
    if(T == NULL) return false;

    return is_abb_aux(T->raiz);
}