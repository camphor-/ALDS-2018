package main

import (
	"exhaustive_search"
)


func main() {
	problems, err := exhaustive_search.NewProblemsFromStdin()
	if err != nil {
		panic(err)
	}

	/* inject solver */
	solver := exhaustive_search.NewExhaustiveSolver()
	//solver := DynamicSolver()

	/* Solve */
	solver.SolveAll(problems)
	problems.Print()
}
