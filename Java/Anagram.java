// # Anagram

// ## Problem Statement

// Write a program that takes two strings as input and determines if they are anagrams of each other. An anagram is a word or phrase formed by rearranging the letters of another.

// Your program should print "Anagram" if the two input strings are anagrams and "Not Anagram" if they are not.

// ## Input

// - Two strings, `str1` and `str2`, consisting of lowercase or uppercase letters and spaces.

// ## Output

// - "Anagram" if the two input strings are anagrams.
// - "Not Anagram" if the two input strings are not anagrams.

// ## Example

// #### Input
// str1 = "listen"
// str2 = "silent"

// #### Output
// Anagram




import java.util.*;

public class Anagram{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String s1,s2;
        System.out.println("Enter string 1");
        s1=sc.next();
        System.out.println("Enter string 2");
        s2=sc.next();

        char arr1[] = s1.toCharArray();
        char arr2[] = s2.toCharArray();
        
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        boolean res = Arrays.equals(arr1,arr2);

        if(res==true)
            System.out.println("Anagram");
        else
            System.out.println("Not Anagram");

    }
}