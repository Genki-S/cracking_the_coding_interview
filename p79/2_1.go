package main

import (
	"container/list"
)

func removeDuplicates(l *list.List) {
	m := make(map[interface{}]bool)
	var next *list.Element
	for e := l.Front(); e != nil; e = next {
		if _, exists := m[e.Value]; exists {
			next = e.Next()
			l.Remove(e)
		} else {
			m[e.Value] = true
			next = e.Next()
		}
	}
}
