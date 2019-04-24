#define CATCH_CONFIG_MAIN
#include <cmath>
#include "catch.hpp"


int gcd(int u, int v) {
    if (u < 0) {
        u = abs(u);
    }
    if (v < 0) {
        v = abs(v);
    }
    if (u == 0 and v == 0) {
        return -1;
    }
    while (v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

TEST_CASE("calculates the greatest common devider", "[gcd]") {
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
    REQUIRE(gcd(3, -7) == 1);
    REQUIRE(gcd(0, 0) == -1);
    REQUIRE(gcd(1, 1) == 1);

}

int checksum(int zahl) {
    int quersumme = 0;
    while (zahl > 0) {
        quersumme += zahl % 10;
        zahl = zahl / 10;
    }

    return quersumme;
}

TEST_CASE("calculates the cross total", "[checksum]") {
    REQUIRE(checksum(120477) == 21);
    REQUIRE(checksum(1) == 1);
    REQUIRE(checksum(12) == 3);
    REQUIRE(checksum(10000) == 1);
}

int sum_multiplies() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

TEST_CASE("sum_multiplies") {
    REQUIRE(sum_multiplies() == 234168);
}

float zylv(int r, int h) {
    return M_PI * (r * r) * h;
}

float zyla(int r, int h) {
    return 2 * M_PI * r * (r + h);
}


TEST_CASE("V and A von Zylinder") {
    REQUIRE(zyla(2, 2) == Approx(50.265));
    REQUIRE(zylv(2, 2) == Approx(25.13274));
}

int fak(int n) {
    if (n < 0){
        return -1;
    }
    if (n == 0) {
        return 1;
    } else {
        return n * fak(n - 1);
    }
}


TEST_CASE(" factorial ", "[fak]") {
    REQUIRE(fak(5) == 120);
    REQUIRE(fak(1) == 1);

}


bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

TEST_CASE(" is_prime ", "[x]") {
    REQUIRE(is_prime(101));

}

float fract(float in_float_number) {
    return in_float_number - int(in_float_number);
}

