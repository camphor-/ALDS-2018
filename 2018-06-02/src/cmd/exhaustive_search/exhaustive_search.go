package main

import (
	"exhaustive_search"
)


func main() {
	/* Read problems from stdin */
	problems, err := exhaustive_search.NewProblemsFromStdin()
	if err != nil {
		panic(err)
	}

	/* inject solver */
	solver := exhaustive_search.NewExhaustiveSolver()
	//solver := DPSolver()

	/* Solve */
	solver.SolveAll(problems)
	problems.Print()
}
