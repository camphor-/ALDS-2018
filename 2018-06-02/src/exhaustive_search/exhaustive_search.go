package exhaustive_search

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type Problems struct {
	A []int
	M []int
	Answer []bool
}

type problem struct {
	i int
	m int
}

func NewProblemsFromStdin() (*Problems, error) {
	s := bufio.NewScanner(os.Stdin)

	/* Read n*/
	ok := s.Scan()
	if !ok {
		return nil, fmt.Errorf("expected n")
	}
	n, err := strconv.Atoi(s.Text())
	if err != nil {
		return nil, fmt.Errorf("expected single int n")
	}

	ok = s.Scan()
	if !ok {
		return nil, fmt.Errorf("expected A")
	}
	aStr := s.Text()
	as := bufio.NewScanner(strings.NewReader(aStr))
	as.Split(bufio.ScanWords)

	ok = s.Scan()
	if !ok {
		return nil, fmt.Errorf("expected q")
	}
	q, err := strconv.Atoi(s.Text())
	if err != nil {
		return nil, fmt.Errorf("expected single int q")
	}

	p := &Problems{
		A: make([]int, 0, n),
		M: make([]int, 0, q),
		Answer: make([]bool, q),
	}

	ok = s.Scan()
	if !ok {
		return nil, fmt.Errorf("expected A")
	}
	mStr := s.Text()
	ms := bufio.NewScanner(strings.NewReader(mStr))
	ms.Split(bufio.ScanWords)

	for as.Scan() {
		a, err := strconv.Atoi(as.Text())
		if err != nil {
			return nil, fmt.Errorf("expected space delimited list of ints, got %s: %s", aStr, err.Error())
		}
		p.A = append(p.A, a)
	}

	for ms.Scan() {
		m, err := strconv.Atoi(ms.Text())
		if err != nil {
			return nil, fmt.Errorf("expected space delimited list of ints, got %s: %s", mStr, err.Error())
		}
		p.M = append(p.M, m)
	}

	return p, nil
}

func (p Problems) Print() {
	for _, ans := range p.Answer {
		switch ans {
		case true:
			fmt.Println("yes")
		case false:
			fmt.Println("no")
		}
	}
}

type Solver interface {
	SolveAll(p *Problems)
	solve(p problem) bool
}

type ExhaustiveSolver struct {
	problems *Problems
}

func NewExhaustiveSolver() Solver {
	return &ExhaustiveSolver{}
}

func (s *ExhaustiveSolver) SolveAll(p *Problems) {
	s.problems = p
	for mIdx, m := range s.problems.M {
		s.problems.Answer[mIdx] = s.solve(problem{
			m: m,
			i: 0,
		})
	}
}

func (s *ExhaustiveSolver) solve(p problem) bool {
	if p.m == 0 {
		return true
	}
	if p.i >= len(s.problems.A) {
		return false
	}
	return s.solve(problem{
		m: p.m,
		i: p.i+1,
	}) || s.solve(problem{
		m: p.m - s.problems.A[p.i],
		i: p.i + 1,
	})
}

type DPSolver struct {
	problems *Problems
	memo map[problem]bool
}

func NewDPSolver() Solver {
	return &DPSolver{
		memo: make(map[problem]bool),
	}
}

func (s *DPSolver) SolveAll(p *Problems) {
	s.problems = p
	for mIdx, m := range s.problems.M {
		s.problems.Answer[mIdx] = s.solve(problem{
			m: m,
			i: 0,
		})
	}
}

func (s *DPSolver) solve(p problem) bool {
	if r, ok := s.memo[p]; ok {
		return r
	}
	if p.m == 0 {
		s.memo[p] = true
		return true
	}
	if p.i >= len(s.problems.A) {
		s.memo[p] = false
		return false
	}
	r := s.solve(problem{
		m: p.m,
		i: p.i+1,
	}) || s.solve(problem{
		m: p.m - s.problems.A[p.i],
		i: p.i + 1,
	})
	s.memo[p] = r
	return r
}
