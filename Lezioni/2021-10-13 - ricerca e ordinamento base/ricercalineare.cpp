bool ricercaLineare(int insieme[], int x, int n) {
    bool trovato=false;
    for (int i = 0; i < n && !trovato; ++i) {
        if (insieme[i] == x) trovato=true;
    }
    return trovato;
}