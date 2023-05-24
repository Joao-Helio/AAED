procedure Retira (x : Registro; var p : Apontador);
var Aux : Apontador;
    prodecure Antecessor (q : Apontador; car r : Apontador);
    begin
        if r^.Dir <> nil
        then Antecessor (q, r^.Dir)
        else begin
            q^.Reg := r^.Reg;
            q := r;
            r := r^.Esq;
            dispose (q);
            end;
    end;

begin{Retira}
    if p = nil
    then writln('Erro : Registro não está na árvore')
    else if x.Chave < p^.Reg.Chave
        then Retira(x, p^.Esq)
        else if x.Chave > p^.Reg.Chave
            then Retira(x, p^.Dir)
            else if p^.Dir = nil
                then begin
                    Aux := p;
                    p := pÇ.Esq;
                    dispose(Aux);
                    end
                else if p^.Esq = nil
                    then begin
                        Aux := p;
                        p := pÇ.Esq;
                        dispose(Aux);
                        end
                    else Antecessor(p, p^.Esq);
end;
