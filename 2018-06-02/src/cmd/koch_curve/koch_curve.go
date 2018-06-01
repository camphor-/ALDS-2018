package main

import (
	"bufio"
	"strconv"
	"os"

	"koch_curve"
)
func main() {
	s := bufio.NewScanner(os.Stdin)
	if !s.Scan() {
		panic("expected int n")
	}
	n, err := strconv.Atoi(s.Text())
	if err != nil {
		panic("failed to obtain n: " + err.Error())
	}
	res := koch_curve.Recurse(koch_curve.Point{X: 0, Y: 0}, koch_curve.Point{X: 100, Y: 0}, n)
	for _, p := range res {
		p.Print()
	}
}
