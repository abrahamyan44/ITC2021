import React from 'react';
import './Notifications.css';
import SimpleNotification from './SimpleNotification';
import { H4 } from 'ui-neumorphism';

class Notifications extends React.Component {
    render () {
        const {dark} = this.props 
        return (
            <div>
                <H4 className='title-notifications' dark={dark}>Notifications</H4>
                <SimpleNotification dark = {dark} title = {'Dinner'} content = {'You havent logged your Dinner for today. Would you liketo do it now?'}/>
            </div>
        )
    }
}

export default Notifications;
