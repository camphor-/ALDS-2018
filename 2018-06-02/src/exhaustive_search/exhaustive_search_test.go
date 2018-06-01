package exhaustive_search

import (
	"testing"
	"reflect"
)

func TestExhaustiveSolver_SolveAll(t *testing.T) {
	solver := NewExhaustiveSolver()
	tests := []struct{
		in Problems
		out []bool
	}{
		{
			in: Problems{
				A:      []int{1, 5, 7, 10, 21},
				M:      []int{2, 4, 17, 8},
				Answer: make([]bool, 4),
			},
			out: []bool{false, false, true, true},
		},
	}

	for _, test := range tests {
		t.Run("1", func (t *testing.T) {
			solver.SolveAll(&test.in)
			if !reflect.DeepEqual(test.in.Answer, test.out) {
				t.Errorf("results did not match: got %v, expected %v", test.in.Answer, test.out)
			}
		})
	}
}

func TestDPSolver_SolveAll(t *testing.T) {
	solver := NewDPSolver()
	tests := []struct{
		in Problems
		out []bool
	}{
		{
			in: Problems{
				A:      []int{1, 5, 7, 10, 21},
				M:      []int{2, 4, 17, 8},
				Answer: make([]bool, 4),
			},
			out: []bool{false, false, true, true},
		},
	}

	for _, test := range tests {
		t.Run("1", func (t *testing.T) {
			solver.SolveAll(&test.in)
			if !reflect.DeepEqual(test.in.Answer, test.out) {
				t.Errorf("results did not match: got %v, expected %v", test.in.Answer, test.out)
			}
		})
	}
}
