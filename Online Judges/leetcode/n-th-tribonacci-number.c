int tribonacci(int n){
    int myNumber=0; // 1 1 2
    int next1=1;    // 1 2 4
    int next2=1;    // 2 4 7
    int next3=2;    // 4 7 13
    for (char i=0;i<n-3;i++){
        myNumber=next1;
        next1=next2;
        next2=next3;
        next3=next2+next1+myNumber;
    }
    return next3;
}

int superTribonacci(int n){
    int myNumber=0; // 1 1 2
    int next1=1;    // 1 2 4
    int next2=1;    // 2 4 7
    int next3=2;    // 4 7 13
    switch (n){
        case 0: return 0;
        case 1: return 1;
        case 2: return 1;
        case 3: return 2;
        default: {
            for (char i=0;i<n-3;i++){
                myNumber=next1;
                next1=next2;
                next2=next3;
                next3=next2+next1+myNumber;
            }
        }
    }
    return next3;
}