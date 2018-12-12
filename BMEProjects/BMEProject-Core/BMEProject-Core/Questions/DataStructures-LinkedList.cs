using System;

namespace DataStructures
{
    partial class LinkedList< TData >
    {
        private class Node
        {
            public Node Next { get; set; }
            public TData Data { get; private set; }

            public Node( TData newData ) { Next = null; Data = newData; }
        }

        private Node Tail { get; set; }
        private Node Head { get; set; }
        public int Count { get; private set; }

        public LinkedList( ) { Tail = null; Head = null; Count = 0; }

        public void AddLast( TData newData )
        {
            if( newData == null ) throw new ArgumentNullException( );

            Node newNode = new Node( newData );
            Node oldTail = Tail;

            if( Head == null ) Head = newNode;
            else oldTail.Next = newNode;
            Tail = newNode;

            Count ++;
        }

        public TData[ ] ToArray( )
        {
            TData[ ] result = new TData[ Count ] ;

            int i = 0;
            Node currentNode = Head;
            while( currentNode != null )
            {
                result[ i ] = currentNode.Data;
                i ++;
                currentNode = currentNode.Next;
            }

            return result;
        }
    }
}
