package main

import (
	"testing"
	"container/list"
	"math/rand"
	"time"
)

func TestCenterOf(t *testing.T) {
	MAX_N := 100
	rand.Seed(time.Now().UTC().UnixNano())
	l := list.New()

	e := centerOf(l)
	if e != nil {
		t.Error("Expected nil, Got: %d", e.Value)
	}

	n1 := rand.Intn(MAX_N)
	l.PushBack(n1)
	e = centerOf(l)
	if e.Value != n1 {
		t.Error("Expected %d, Got: %d", n1, e.Value)
	}

	n2 := rand.Intn(MAX_N)
	l.PushBack(n2)
	e = centerOf(l)
	if e.Value != n1 {
		t.Error("Expected %d, Got: %d", n1, e.Value)
	}

	n3 := rand.Intn(MAX_N)
	l.PushBack(n3)
	e = centerOf(l)
	if e.Value != n2 {
		t.Error("Expected %d, Got: %d", n2, e.Value)
	}
}

func TestRemoveCenter(t *testing.T) {
	l := list.New()

	l.PushBack(1)
	removeCenter(l)
	if l.Front() != nil {
		t.Error()
	}

	l = list.New()
	l.PushBack(1)
	l.PushBack(2)
	removeCenter(l)
	if l.Front().Value != 2 {
		t.Error()
	}

	l = list.New()
	l.PushBack(1)
	l.PushBack(2)
	l.PushBack(3)
	removeCenter(l)
	if l.Len() != 2 || l.Front().Value != 1 || l.Back().Value != 3 {
		t.Error()
	}
}
