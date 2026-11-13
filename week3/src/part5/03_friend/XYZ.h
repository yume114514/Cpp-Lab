#ifndef XYZ_H
#define XYZ_H

class X;

class Y {
public:
    void g(X* px);
};

class Z {
public:
    void f(X* px);
};

void h(X* px);

class X {
private:
    int i;
public:
    explicit X(int v = 0) : i(v) {}
    int getI() const { return i; }

    friend void Y::g(X* px);
    friend class Z;
    friend void h(X* px);
};

inline void Y::g(X* px) { px->i += 1; }
inline void Z::f(X* px) { px->i += 5; }
inline void h(X* px) { px->i += 10; }

#endif
