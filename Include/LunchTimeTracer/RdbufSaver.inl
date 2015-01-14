/* Author:			lutter
 * Created:			14.01.2015
 * Since version:	0.1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LunchTimeTracer_RdbufSaver_inl_included
#define LunchTimeTracer_RdbufSaver_inl_included

template <typename Ch, class Tr>
LTT_TrippyColors::BasicIosRdbufSaver<Ch, Tr>::BasicIosRdbufSaver(StateType& State)
	: State(State), Aspect(State.rdbuf())
{
}

template <typename Ch, class Tr>
LTT_TrippyColors::BasicIosRdbufSaver<Ch, Tr>::BasicIosRdbufSaver(StateType& State, AspectType const& Aspect)
	: State(State), Aspect(State.rdbuf(Aspect))
{
}

template <typename Ch, class Tr>
LTT_TrippyColors::BasicIosRdbufSaver<Ch, Tr>::~BasicIosRdbufSaver()
{
	Restore();
}

template <typename Ch, class Tr>
void LTT_TrippyColors::BasicIosRdbufSaver<Ch, Tr>::Restore()
{
	State.rdbuf(Aspect);
}

#endif // LunchTimeTracer_RdbufSaver_inl_included
