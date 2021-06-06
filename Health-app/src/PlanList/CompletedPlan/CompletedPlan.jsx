import React from 'react';
import './CompletedPlan.css';
import {mdiRun} from '@mdi/js';
import Icon from '@mdi/react'
import {
    H5,
    Card,
    Caption,
  } from 'ui-neumorphism'

class CompletedPlan extends React.Component {
    render() {
      const {dark} = this.props;
        return(
            <div className='completed-plan-block'>
              <Card className='completed-plan-card' dark={dark} elevation={3}>
                <Card flat>
                  <Icon path={mdiRun} size={2.5} color='var(--primary)'/>
                  <H5 className='current-value'>8,690</H5>
                  <Caption className='goal' secondary >Goal: 12k</Caption>
                </Card>
              </Card>
            </div>
        )
    }
}

export default CompletedPlan;