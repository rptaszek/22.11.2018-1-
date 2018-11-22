#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//#define TEST

double licz_delta(double a, double b, double c) {
    return b * b - 4 * a * c;
}

int rozwiaz_rownanie_kwadratowe(double a, double b, double c, double *px1, double *px2) {
    double delta;

    if (a == 0.0 && b == 0.0 && c == 0.0) {
        printf("Równanie jest tautologią.\n");
        return 1;
    }

    if (a == 0.0 && b == 0.0) {
        printf("Równanie dla podanych parametrów jest sprzeczne.\n");
        return 2;
    }

    if (a == 0.0) {
        printf("Równanie liniowe.\n");
        *px1 = -c / b;
        return 3;
    }

    // kolejne przypadki to równanie kwadratowe
    printf("Równanie kwadratowe. ");

    delta = licz_delta(a, b, c);

    if (delta > 0.0) {
        printf("Istnieją dwa rozwiązania.\n");
        *px1 = (-b - sqrt(delta)) / (2.0 * a);
        *px2 = (-b + sqrt(delta)) / (2.0 * a);
        return 4;
    }
    if (delta == 0.0) {
        printf("Istnieje jedno rozwiązanie.\n");
        *px1 = -b / (2.0 * a);
        return 5;
    }
    if (delta < 0.0) {
        printf("Nie ma rozwiążań w dziedzinie liczb rzeczywistych.\n");
        return 6;
    }

    return 0;
}

#ifdef TEST

void nd(int licznik) { printf("Test nr %i nie działa\n", licznik); }

// tutaj należy umieszczać kolejne testy
void test1_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (0, 0, 0) - tautologia
    if (rozwiaz_rownanie_kwadratowe(0.0, 0.0, 0.0, &x1, &x2) != 1) nd(licznik);
}

void test2_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (0, 0, 5) - rozwiązanie nie istnieje - funkcja jest sprzeczna
    if (rozwiaz_rownanie_kwadratowe(0.0, 0.0, 5.0, &x1, &x2) != 2) nd(licznik);
    if (rozwiaz_rownanie_kwadratowe(0.0, 0.0, -3.4, &x1, &x2) != 2) nd(licznik);
}

void test3_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (0, 2, 5) - równanie liniowe
    if (rozwiaz_rownanie_kwadratowe(0.0, 2.0, 5.0, &x1, &x2) != 3) nd(licznik);
    if (x1 != -5.0 / 2.0) nd(licznik);

    if (rozwiaz_rownanie_kwadratowe(0.0, -52.3, 6.2, &x1, &x2) != 3) nd(licznik);
    if (x1 != 6.2 / 52.3) nd(licznik);
}

void test4_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (1.1, 3.2, 2.1) - równanie kwadratowe, delta > 0
    if (rozwiaz_rownanie_kwadratowe(1.1, 3.2, 2.1, &x1, &x2) != 4) nd(licznik);
    if (x1 != (-3.2 - sqrt(licz_delta(1.1, 3.2, 2.1))) / (2.0 * 1.1)) nd(licznik);
    if (x2 != (-3.2 + sqrt(licz_delta(1.1, 3.2, 2.1))) / (2.0 * 1.1)) nd(licznik);
}

void test5_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (1.0, 2.0, 1.0) - równanie kwadratowe, delta = 0
    if (rozwiaz_rownanie_kwadratowe(1.0, 2.0, 1.0, &x1, &x2) != 5) nd(licznik);
    if (x1 != -2.0 / (2.0 * 1.0)) nd(licznik);
}

void test6_rownanie_kwadratowe(int licznik) {
    double x1;
    double x2;

    //dla (5.1, 1.2, 5.1) - równanie kwadratowe, delta < 0
    if (rozwiaz_rownanie_kwadratowe(5.1, 1.2, 5.1, &x1, &x2) != 6) nd(licznik);
}

void test7_testuje_obliczanie_delty(int licznik) {
    if (licz_delta(3.0, 4.0, 1.0) != 4.0) nd(licznik);
}

void run_test_pool() {
    int licznik = 0;
// tutaj wywołujemy testy
    test1_rownanie_kwadratowe(++licznik);
    test2_rownanie_kwadratowe(++licznik);
    test3_rownanie_kwadratowe(++licznik);
    test4_rownanie_kwadratowe(++licznik);
    test5_rownanie_kwadratowe(++licznik);
    test6_rownanie_kwadratowe(++licznik);
    test7_testuje_obliczanie_delty(++licznik);
}

#endif


int main() {

#ifndef TEST
    double a, b, c;
    double x1, x2;
    int przypadek;

    // uruchom program
    printf("Program liczy pierwiastki równania kwadratowego:\n");
    printf("ax^2 + bx + c = 0\n");
    printf("Podaj współczynniki\n");

    printf("a = "); scanf("%lf", &a);
    printf("b = "); scanf("%lf", &b);
    printf("c = "); scanf("%lf", &c);

    przypadek = rozwiaz_rownanie_kwadratowe(a, b, c, &x1, &x2);

    switch (przypadek) {
        case 4:
            printf("x1 = %lf\n", x1);
            printf("x1 = %lf\n", x1);
            break;
    }



#else
    // uruchom testy
    run_test_pool();

#endif

    return 0;
}