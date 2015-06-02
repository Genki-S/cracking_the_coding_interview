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
	// n := e.next
	// if n == nil {
	//   return
	// }
	// e.Value = n.Value
	// e.next = n.next
	l.Remove(e)
}
