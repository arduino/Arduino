/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer.utils;

import java.util.LinkedList;

public class LimitedQueue<E> extends LinkedList<E> {

    private int limit;

    public LimitedQueue(int limit) {
        this.limit = limit;
    }

    @Override
    public boolean add(E o) {
        boolean added = super.add(o);
        while (added && size() > limit) {
           super.remove();
        }
        return added;
    }
    
    @Override
    public void push(E o) {
      if (size() == limit) {
        super.removeLast();
      }
      super.push(o);
    }

}
