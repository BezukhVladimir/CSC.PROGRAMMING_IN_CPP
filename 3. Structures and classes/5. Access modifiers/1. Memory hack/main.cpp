struct ClsClone
{
    ClsClone(char c_, double d_, int i_) {}
    
    char c;
    double d;
    int i;
};

char & get_c(Cls &cls) {
    return ((ClsClone *) &cls)->c;
}

double & get_d(Cls &cls) {
    return ((ClsClone *) &cls)->d;
}

int & get_i(Cls &cls) {
    return ((ClsClone *) &cls)->i;
}