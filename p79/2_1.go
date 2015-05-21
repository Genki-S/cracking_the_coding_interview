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

func removeDuplicatesWithoutBuffer(l *list.List) {
	for e := l.Front(); e != nil; e = e.Next() {
		for ee := e.Next(); ee != nil; ee = ee.Next() {
			if ee.Value == e.Value {
				prev := ee.Prev()
				l.Remove(ee)
				ee = prev
			}
		}
	}
}
