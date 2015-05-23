package main

import (
	"testing"
	"container/list"
	"math/rand"
	"time"
)

func TestGetReverseAt(t *testing.T) {
	rand.Seed(time.Now().UTC().UnixNano())

	MAX_N := 100
	l := list.New()

	limit := rand.Intn(MAX_N)
	for i := 0; i < limit; i++ {
		n := rand.Intn(MAX_N)
		l.PushBack(n)
	}

	reversed := make([]interface{}, limit)
	for i, e := 0, l.Back(); e != nil; i, e = i+1, e.Prev() {
		reversed[i] = e.Value
	}

	for i := 0; i < limit; i++ {
		exp := reversed[i]
		act := getReverseAt(l, i)
		if act != exp {
			t.Error("Expected: %d, Actual: %d", exp, act)
		}
	}
}
