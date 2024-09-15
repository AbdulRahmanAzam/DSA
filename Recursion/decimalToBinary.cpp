
// return the int
// multiplying by 10 so that it will add another number to the right
int decimaltobinary(int n){
    if(!n)
        return n; 
        
    return decimaltobinary(n/2) * 10 + (n%2);    
}


// prints the binary
void decimaltobinary(int n){
    if(!n)
        return;
        
    decimaltobinary(n/2);
    cout << n%2;
    return;
}
