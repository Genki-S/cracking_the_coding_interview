package main

import (
	"testing"
	"container/list"
	"math/rand"
	"time"
)

func removeDuplicatesTester(t *testing.T, targetFunc func(*list.List)) {
	rand.Seed(time.Now().UTC().UnixNano())

	MAX_N := 100
	testList := list.New()
	ansList := list.New()

	m := make(map[int]bool)
	for i := 0; i < 1000; i++ {
		n := rand.Intn(MAX_N)
		testList.PushBack(n)
		if _, exists := m[n]; !exists {
			m[n] = true
			ansList.PushBack(n)
		}
	}

	targetFunc(testList)

	if testList.Len() != ansList.Len() {
		t.Error("unexpected length")
	}

	for te, ae := testList.Front(), ansList.Front(); te != nil || ae != nil; te, ae = te.Next(), ae.Next() {
		if te == nil || ae == nil {
			t.Error("unexpected nil")
		}
		if te.Value != ae.Value {
			t.Error("unexpected value")
		}
	}
}

func TestRemoveDuplicates(t *testing.T) {
	removeDuplicatesTester(t, removeDuplicates)
}

func TestRemoveDuplicatesWithoutBuffer(t *testing.T) {
	removeDuplicatesTester(t, removeDuplicatesWithoutBuffer)
}
