/*
	SubmissionId	:	39785390
	ContestId	:	1001
	Index	:	B
	ProblemName	:	Generate Bell state
	ProblemTags	:	['*special']
	ProgrammingLanguage	:	Q#
	Verdict	:	OK
*/

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }


    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if (index % 2 == 0) {
                Set(Zero, qs[0]); }
            if (index % 2 == 1) {
                Set(One, qs[0]); }
            if (index / 2 == 0) {
                Set(Zero, qs[1]); }
            if (index / 2 == 1) {
                Set(One, qs[1]); }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }
}