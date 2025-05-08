class Point:
    def __init__(self, x, y, a, p):
        self.x = x
        self.y = y
        self.a = a
        self.p = p

    def __add__(self, other):
        if other is None:
            return self
        if self.x == other.x and self.y == (-other.y % self.p):
            return None
        if self.x == other.x and self.y == other.y:
            if self.y == 0:
                return None
            s = (3 * self.x**2 + self.a) * pow(2 * self.y, self.p - 2, self.p) % self.p
        else:
            s = (other.y - self.y) * pow(other.x - self.x, self.p - 2, self.p) % self.p
        x3 = (s**2 - self.x - other.x) % self.p
        y3 = (s * (self.x - x3) - self.y) % self.p
        return Point(x3, y3, self.a, self.p)

def main():
    a = 2
    p = 17
    p1 = Point(5, 1, a, p)
    p2 = Point(6, 3, a, p)
    result = p1 + p2
    if result is None:
        print(f"({p1.x}, {p1.y}) + ({p2.x}, {p2.y}) = Point at infinity")
    else:
        print(f"({p1.x}, {p1.y}) + ({p2.x}, {p2.y}) = ({result.x}, {result.y})")

if __name__ == "__main__":
    main()
