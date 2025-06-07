int climbStairs(int n) {
    int pre2=0;
    int pre1=1;
    int new=0;

    for (int i=0;i<n;i++){
        new = pre2+pre1;
        pre2=pre1;
        pre1=new;
    }
    return new;
}
