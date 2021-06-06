import React from 'react';
import './Notifications.css';
import SimpleNotification from './SimpleNotification';
import NavigationBar from '../NavigationBar/NavigationBar';
import { H4,Card } from 'ui-neumorphism';

class Notifications extends React.Component {
    render () {
        const {dark} = this.props 
        return (
            <Card rounded width={300} height={600} dark = {dark} className='notifications-card'>
                <H4 className='title-notifications'>Notifications</H4>
                <SimpleNotification dark = {dark} title = {'Dinner'} content = {'You havent logged your Dinner for today. Would you liketo do it now?'}/>

                <NavigationBar selected = {'Notifications'} dark = {dark}/>
            </Card>
        )
    }
}

export default Notifications;
