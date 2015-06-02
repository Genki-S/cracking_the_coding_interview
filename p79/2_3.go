package main

import (
	"container/list"
)

func centerOf(l *list.List) *list.Element {
	len := l.Len()
	target := (len - 1) / 2
	e := l.Front()
	for i := 0; i != target; i++ {
		e = e.Next()
	}
	return e
}

func removeCenter(l *list.List) {
	e := centerOf(l)
	if e == nil {
		return
	}

	// cannot refer to unexported field or method
	// p := e.prev
	// n := e.next
	// if p != nil {
	// p.next = n
	// }
	// if n != nil {
	// n.prev = p
	// }
	l.Remove(e)
}
