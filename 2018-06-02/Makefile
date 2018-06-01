GOPATH := ${PWD}

test:
	GOPATH=${GOPATH} go test exhaustive_search
	GOPATH=${GOPATH} go test koch_curve

exhaustive_search:
	GOPATH=${GOPATH} go build -o bin/exhaustive_search src/cmd/exhaustive_search/exhaustive_search.go

koch_curve:
	GOPATH=${GOPATH} go build -o bin/koch_curve src/cmd/koch_curve/koch_curve.go
