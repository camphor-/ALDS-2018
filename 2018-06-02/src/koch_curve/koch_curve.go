package koch_curve

import (
	"fmt"
	"math"
)

type Point struct {
	X float64
	Y float64
}

func (p *Point) Rotate(rad float64) *Point {
	return &Point{
		X: p.X * math.Cos(rad) - p.Y * math.Sin(rad),
		Y: p.X * math.Sin(rad) + p.Y * math.Cos(rad),
	}
}

func (p *Point) Print() {
	fmt.Printf("%f %f\n", p.X, p.Y)
}

func (p *Point) String() string {
	return fmt.Sprintf("%f, %f", p.X, p.Y)
}

/* TODO: change name */
/*
 *           Q
 *           *
 *
 *   *    *     *     *
 *   A    P     R     B
 */
func Recurse(a, b Point, d int) []Point {
	p := Point{
		X: (a.X * 2 + b.X * 1) / 3,
		Y: (a.Y * 2 + b.Y * 1) / 3,
	}
	r := Point{
		X: (a.X * 1 + b.X * 2) / 3,
		Y: (a.Y * 1 + b.Y * 2) / 3,
	}
	pr := Point{
		X: r.X - p.X,
		Y: r.Y - p.Y,
	}
	rotatedPr := pr.Rotate(math.Pi / 3)
	q := Point{
		p.X + rotatedPr.X,
		p.Y + rotatedPr.Y,
	}
	seg := []Point{a, p, q, r, b}
	res := make([]Point, 0)
	if d == 1 {
		return seg
	} else {
		for i := 0; i < len(seg) - 2; i++ {
			r := Recurse(seg[i], seg[i+1], d-1)
			res = append(res, r[:len(r)-1]...)
		}
		return res
	}
}
