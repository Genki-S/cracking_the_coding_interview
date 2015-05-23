package main

import (
	"container/list"
)

func getReverseAt(l *list.List, index int) interface{} {
	len := l.Len()
	target := len - 1 - index
	e, i := l.Front(), 0
	for i != target {
		e, i = e.Next(), i+1
		if e == nil {
			return nil
		}
	}
	return e.Value
}
