#include <iostream>
#include <fstream>
#include <valarray>


void task2a();
void task2b();
void task3();
void task1();
void Kolm();

using namespace std;

int main() {

    Kolm();
    return 0;
}

void Kolm() {
    double answ=0.967643;
        double sum = 0;
        for (int k = -2000; k <= 2000; k++) {
            sum += pow(-1, k) * pow(exp(1), -2*k * k * answ*answ);
        }
        cout <<1- sum << "\n";
}
void task3() {
    double So1=0.0;
    double So2=0.0;
    double input;
    double n=20.0, m=30.0;
    ifstream fin("input.txt");
    int i=0;
    double x1=0.0;
    double x2=0.0;
    while (!fin.eof()) {
        fin >> input;
        if(i<n) {
            x1+=input;
        }
        if(i>=n) {
            x2+=input;
        }
        i++;
    }
    x1/=n;
    x2/=m;
    fin.seekg(0);

    i=0;
    double x21=0.0;
    double x22=0.0;
    while (!fin.eof()) {
        fin >> input;
        if(i<n) {
            x21+=input*input;
        }
        if(i>=n) {
            x22+=input*input;
        }
        i++;
    }
    x21/=n;
    x22/=m;

    So1=(n/(n-1))*(x21-x1*x1);
    So2=(m/(m-1))*(x22-x2*x2);
    if(So1>So2){
        cout << "first \t" << So1/So2 << '\n';
    }else{
        cout << "first \t" << So2/So1 << '\n';
    }

    cout << "second \t" << abs((x1-x2)/ sqrt(n*(x21-x1*x1)+m*(x22-x2*x2))*sqrt(((n+m-2)*n*m)/(n+m)));
}

void task2b(){
    double n=5;
    double psi=0.0;
    ifstream fin("in2.txt");
    for(double i=0;i<1;i+=1/n) {
        double input = 0;
        double Vi = 0;
        while (!fin.eof()) {
            fin >> input;
            if(input>=i && input<i+1/n) {
                Vi ++;
            }
        }
        cout << "interval (" << i << ";" << i+1/n <<") points: " << Vi << '\n';
        psi+=pow((Vi-30*1/n),2)/(30*1/n);
        fin.seekg(0);

    }
    cout<< "Psi : " << psi;
    fin.close();
}

void task2a() {
    double F=0.0;
    double prev=0.0;
    double D = 0;
    double Xmax=0.0;
    ifstream fin("in2.txt");
    for(;F<=1;F+=0.01) {
        double input = 0;
        double Fn = 0;
        while (!fin.eof()) {
            fin >> input;
            if(input<F) {
                Fn ++;
            }
        }
        //

        Fn /= 30;

            //cout << "-d : " << abs(Fn-F)<< '\t'<< abs(prev - F) << '\n';

        if (abs(Fn - F) > D) {
            D = abs(Fn - F);
            Xmax=F;
        }
        if (abs(prev - F) > D) {
            D = abs(prev - F);
            Xmax=F-0.001;
        }
        prev = Fn;
        fin.seekg(0);

    }
    cout<< "D : " << D << " place: " << Xmax;
    fin.close();
}

void task1(){
    double input=0, sum = 0;
    ifstream fin("input.txt");
    while (!fin.eof()){
        fin >> input;

        sum += input;
    }
    sum/=50;

    cout << "-X : "<< sum << '\n';
    fin.seekg(0);
    double S0=0;
    while (!fin.eof()){
        fin >> input;
        S0+=pow(input,2)-pow(sum,2);
    }
    cout << "S : " << S0/50 <<'\n';
    S0=sqrt(S0/49);
    cout << "S0 : " << S0 << '\n';
    cout << "a- : " << sum-2.04*sqrt(1.1)/sqrt(50) <<'\n';
    cout << "a+ : " << sum+2.04*sqrt(1.1)/sqrt(50) << '\n';

    fin.seekg(0);
    double S1=0;
    while (!fin.eof()){
        fin >> input;
        S1+=pow(input+2,2);
    }
    cout << "S1 : " << S1<<'\n';
    fin.close();
}

